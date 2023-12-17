#include<bits/stdc++.h>

struct movie {
  int length;
  int happiness;
  double happiness_per_minute;
};

bool compare_movies(const movie& m1, const movie& m2) {
  return m1.happiness_per_minute > m2.happiness_per_minute;
}

int main() {
  int testcase;
  std::cin>>testcase;
while(testcase--){
  int n, t;
  std::cin>>n>>t;
  std::vector<movie> movies(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> movies[i].length >> movies[i].happiness;
    movies[i].happiness_per_minute = static_cast<double>(movies[i].happiness) / movies[i].length;
  }
  sort(movies.begin(), movies.end(), compare_movies);
  int remaining_time = t;
  int total_happiness = 0;
  for (const movie& movie : movies) {
    if (remaining_time >= movie.length) {
      remaining_time -= movie.length;
      total_happiness += movie.happiness;
    } else {
      break;
    }
  }
 std::cout << total_happiness <<std:: endl;
}
  
  return 0;
}