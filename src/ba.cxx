#include <iostream>
#include <array>

const int K = 3;     // Starting with K-Core, it should be small value
//const int N = 100000000; // #Vertices
const int N = 1000;

int main() {
  std::array<int, (K-1) * K + K * (N - K)> edges;
  int *p = edges.begin();
  int *b = p;

  std::cout << "start initialization!" << std::endl;
  // Initally, create a K-Complete Graph
  for (int x = 0; x < K; x++) {
    for (int y = 0; y < K; y++) {
      if(x!=y) *p++ = y;
    }
  }

  for (int x = K; x < N; x++) {
    const int RANGE = p - b;
    for (int i = 0; i < K; i++) {
      const int r = rand() % RANGE; // A random edge
      if (r & 1) *p++ = r / K;      // Save the source of the edge by half chance
      else *p++ = edges[r];         // Save the destination of the edge by another half chance
    }
  }

  for (p = edges.begin(); p < edges.end(); p++) {
    // std::cout << *p << std::endl;
    if (*p < K)
      std::cout << (p - b) / (K-1) << " " << *p << std::endl;
    else
      std::cout << (p - b) / K +1<< " " << *p << std::endl;
  }
}
