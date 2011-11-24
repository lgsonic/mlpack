/***
 * @file nearest_neighbor_sort.cpp
 * @author Ryan Curtin
 *
 * Implementation of the simple FurthestNeighborSort policy class.
 */
#include "furthest_neighbor_sort.hpp"

using namespace mlpack::neighbor;

size_t FurthestNeighborSort::SortDistance(const arma::vec& list,
                                          double new_distance)
{
  // The first element in the list is the nearest neighbor.  We only want to
  // insert if the new distance is greater than the last element in the list.
  if (new_distance < list[list.n_elem - 1])
    return (size_t() - 1); // Do not insert.

  // Search from the beginning.  This may not be the best way.
  for (size_t i = 0; i < list.n_elem; i++)
  {
    if (new_distance >= list[i])
      return i;
  }

  // Control should never reach here.
  return (size_t() - 1);
}
