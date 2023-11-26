#include <catch2/catch.hpp>
#include "csv_routes.hpp"
#include "graph/graph.hpp"
#include "graph/algorithm/tc.hpp"
#include "graph/container/dynamic_graph.hpp"
#include "graph/views/incidence.hpp"
#ifdef _MSC_VER
#  include "Windows.h"
#endif

using std::cout;
using std::endl;

using routes_vol_graph_traits = std::graph::container::vol_graph_traits<double, std::string, std::string>;
using routes_vol_graph_type   = std::graph::container::dynamic_adjacency_graph<routes_vol_graph_traits>;

TEST_CASE("triangle counting test", "[tc]") {
  init_console();

  using G  = routes_vol_graph_type;
  auto&& g = load_ordered_graph<G>(TEST_DATA_ROOT_DIR "tc_test.csv", name_order_policy::alphabetical, true);

  size_t triangles = std::graph::triangle_count(g);
  REQUIRE(triangles == 11);
}