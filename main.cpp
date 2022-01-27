#include <iostream>
#include <vector>
#include <array>
#include <map>


void helper(std::vector<std::vector<int>> &A, std::map<std::array<unsigned int, 2>, bool> &map,
            std::vector<std::array<unsigned int, 2>> &queue, unsigned int r, unsigned c, int val){
    if (A[r][c] == val){
        std::array<unsigned int, 2> arr = {r, c};
        auto it = map.find(arr);
        if (it == map.end()){
            map[arr] = true;
            queue.push_back(arr);
        }
    }
}


void bfs(std::vector<std::vector<int>> &A, std::map<std::array<unsigned int, 2>, bool> &map,
         std::vector<std::array<unsigned int, 2>> &queue){
    if (queue.empty()) return;
    std::array<unsigned int, 2> arr = queue.back();
    queue.pop_back();
    unsigned int r = arr[0];
    unsigned int c = arr[1];
    int val = A[r][c];
    unsigned int rows = A.size();
    unsigned int cols = A[0].size();
    unsigned int cur_r;
    unsigned int cur_c;
    std::map<std::array<unsigned int, 2>, bool>::iterator it;

    cur_r = r - 1;
    if ((int) cur_r > -1){
        cur_c = c;
        helper(A, map, queue, cur_r, cur_c, val);
    }

    cur_c = c + 1;
    if ((int) cur_c < cols){
        cur_r = r;
        helper(A, map, queue, cur_r, cur_c, val);
    }

    cur_r = r + 1;
    if ((int) cur_r < rows){
        cur_c = c;
        helper(A, map, queue, cur_r, cur_c, val);
    }

    cur_c = c - 1;
    if ((int) cur_c > -1){
        cur_r = r;
        helper(A, map, queue, cur_r, cur_c, val);
    }
    bfs(A, map, queue);
}


int solution(std::vector<std::vector<int>> &A){
    unsigned int rows = A.size();
    unsigned int cols = A[0].size();
    std::map<std::array<unsigned int, 2>, bool> map;
    std::vector<std::array<unsigned int, 2>> queue;
    std::map<std::array<unsigned int, 2>, bool>::iterator it;
    std::array<unsigned int, 2> arr{};
    int counter = 0;
    for (unsigned int r=0; r<rows; r++){
        for (unsigned int c=0; c<cols; c++){
            arr = {r, c};
            it = map.find(arr);
            if (it == map.end()){
                map[arr] = true;
                queue.push_back(arr);
            }
            if (!queue.empty()){
                counter++;
                bfs(A, map, queue);
            }
        }
    }
    return counter;
}



int main() {
    std::vector<std::vector<int>> A = std::vector<std::vector<int>>{
        std::vector<int>{1, 2, 2, 3},
        std::vector<int>{1, 1, 2, 3},
        std::vector<int>{2, 2, 3, 3},
        std::vector<int>{2, 3, 1, 1}
    };
    std::cout << solution(A) << std::endl; // == 6

    A = std::vector<std::vector<int>>{
        std::vector<int>{1, 3, 3, 2},
        std::vector<int>{3, 1, 2, 3},
        std::vector<int>{3, 2, 1, 3},
        std::vector<int>{2, 3, 3, 1}
    };
    std::cout << solution(A) << std::endl; // == 12

    A = std::vector<std::vector<int>>{
        std::vector<int>{1}
    };
    std::cout << solution(A) << std::endl; // == 1

    A = std::vector<std::vector<int>>{
        std::vector<int>{1, 1, 1, 1},
        std::vector<int>{1, 1, 1, 1},
        std::vector<int>{1, 1, 1, 1},
        std::vector<int>{1, 1, 1, 1}
    };
    std::cout << solution(A) << std::endl; // == 1

    A = std::vector<std::vector<int>>{
        std::vector<int>{1, 1, 1, 1},
        std::vector<int>{1, 1, 2, 1},
        std::vector<int>{1, 2, 1, 1},
        std::vector<int>{1, 1, 1, 1}
    };
    std::cout << solution(A) << std::endl; // == 3

    A = std::vector<std::vector<int>>{
        std::vector<int>{1, 1, 1, 2},
        std::vector<int>{1, 1, 2, 1},
        std::vector<int>{1, 2, 1, 1},
        std::vector<int>{2, 1, 1, 1}
    };
    std::cout << solution(A) << std::endl; // == 6

    A = std::vector<std::vector<int>>{
        std::vector<int>{2, 1, 1, 2},
        std::vector<int>{1, 1, 2, 1},
        std::vector<int>{1, 2, 1, 1},
        std::vector<int>{2, 1, 1, 2}
    };
    std::cout << solution(A) << std::endl; // == 8
    return 0;
}
