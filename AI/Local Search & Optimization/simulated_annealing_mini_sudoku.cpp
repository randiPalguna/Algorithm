#include <bits/stdc++.h>

using namespace std;

const int ROW = 4;
const int COL = 4;

void print_sudoku(vector<vector<int>> sudoku) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      cout << sudoku[i][j] << " ";
      if (j == 1) {
        cout << " | ";
      }
    }
    cout << '\n';
    if (i == 1) {
      cout << "----------" << '\n';
    }
  }
}

void generate_state(vector<vector<int>> &sudoku) {
  int initial_x = 0, initial_y = 0;
  int cnt = 0;
  
  while (cnt < 4) {
    int x, y;
    vector<bool> bucket(5, 0); // for generating unique number in 2x2 cell sudoku from 1..4
    bucket[0] = 1; // there is no number 0 in sudoku
    
    y = initial_y;
    for (int i = 0; i < 2; i++) {
      x = initial_x;
      for (int j = 0; j < 2; j++) {
        if (sudoku[y][x] != 0) {
          bucket[sudoku[y][x]] = 1; // mark the fixed sudoku cell number
        }
        x++;
      }
      y++;
    }

    srand(time(0));
    y = initial_y;
    for (int i = 0; i < 2; i++) {
      x = initial_x;
      for (int j = 0; j < 2; j++) {
        if (sudoku[y][x] == 0) {
          int random_num;
          while (1) {
            random_num = rand() % 5;
            if (bucket[random_num] != 1) {
              bucket[random_num] = 1;
              break;
            }
          }
          sudoku[y][x] = random_num;
        }
        x++;
      }
      y++;
    }

    initial_x += 2;
    if (initial_x == 4) {
      initial_x = 0;
      initial_y += 2;
    }
    cnt++;
  }
}

int cost(vector<vector<int>> sudoku) {
  vector<bool> bucket(5);
  vector<bool> dup_bucket(5);
  int ans = 0;

  for (int i = 0; i < ROW; i++) {
    fill (bucket.begin(), bucket.end(), 0);
    fill (dup_bucket.begin(), dup_bucket.end(), 0);
    for (int j = 0; j < COL; j++) {
      if (bucket[sudoku[i][j]] == 0) {
        bucket[sudoku[i][j]] = 1;
      } else {
        if (dup_bucket[sudoku[i][j]] == 0) {
          ans++;
          dup_bucket[sudoku[i][j]] = 1;
        }
      }
    }
  }
  
  for (int i = 0; i < ROW; i++) {
    fill (bucket.begin(), bucket.end(), 0);
    fill (dup_bucket.begin(), dup_bucket.end(), 0);
    for (int j = 0; j < COL; j++) {
      if (bucket[sudoku[j][i]] == 0) {
        bucket[sudoku[j][i]] = 1;
      } else {
        if (dup_bucket[sudoku[j][i]] == 0) {
          ans++;
          dup_bucket[sudoku[j][i]] = 1;
        }
      }
    }
  }
  
  return ans;
}

vector<vector<int>> pick_neighbor(vector<vector<int>> fixed_sudoku, vector<vector<int>> neighbor, int fixed_cells) {
  srand(time(0));
  // pick random 2x2 cell
  int big_cell = rand() % 4;
  int offset_x = (big_cell % 2) * 2;
  int offset_y = (big_cell * 2 / 4) * 2;

  // swap any cell inside the big cell
  // Swapping takes P times in the sudoku using Boltzman statistic 
  int P = (16 - fixed_cells) / 2 * (1 - exp(-cost(neighbor)));
  while (P--) {
    while (1) {
      int x1 = rand() % 2 + offset_x;
      int y1 = rand() % 2 + offset_y;
      int x2 = rand() % 2 + offset_x;
      int y2 = rand() % 2 + offset_y;
      if (fixed_sudoku[y1][x1] == 0 && fixed_sudoku[y2][x2] == 0 && (x1 != x2 || y1 != y2)) {
        swap(neighbor[y1][x1], neighbor[y2][x2]);
        break;
      }
    }
  }

  return neighbor;
}

void simulated_annealing(vector<vector<int>> fixed_sudoku, int fixed_cells) {
  // initialization
  vector<vector<int>> sudoku = fixed_sudoku;
  double T = 200; // temperature
  double alpha = 0.99;
  
  generate_state(sudoku);
  int F = cost(sudoku);
  
  cout << F << '\n';

  vector<vector<int>> neighbor;
  vector<vector<int>> best_neighbor;  
  int stuck_count = 0;
  while (F > 0) {
    // pick the best neighbor from all 10000 generated neighbors
    int F_next = INT_MAX;
    for (int i = 0; i < 100000; i++) {
      neighbor = pick_neighbor(fixed_sudoku, sudoku, fixed_cells);
      if (cost(neighbor) < F_next) {
        F_next = cost(neighbor);
        best_neighbor = neighbor;
      }
    }
    
    // accpet the best picked neighbor ?
    if (F_next < F) { // always accpet this
      stuck_count = 0;
      sudoku = best_neighbor;
      F = F_next;
    } else { // use boltzmann probability to accept or not
      double epsilon = exp(-(F_next - F) / T);
      double rand_1 = ((double) rand() / (RAND_MAX));
      stuck_count++;
      if (rand_1 < epsilon) {
        sudoku = best_neighbor;
        F = F_next;
      }
    }
    if (stuck_count > 80) {
      T += 0.005; // pump the temperature
    }
    T *= alpha;
    cout << "F = " << F << '\n';
    cout << "       T = " << T << '\n';
  }

  cout << "\n\nSOL:\n";
  // Initial sudoku:
  print_sudoku(fixed_sudoku);
  cout << '\n';
  // Solutions:
  print_sudoku(sudoku);
}

int main() {
  // make sudoku
  vector<vector<int>> fixed_sudoku(ROW, vector<int>(COL));
  int fixed_cells;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      cin >> fixed_sudoku[i][j];
      if (fixed_sudoku[i][j] != 0) {
        fixed_cells++;
      }
    }
  }
  simulated_annealing(fixed_sudoku, fixed_cells);
  return 0;
}
