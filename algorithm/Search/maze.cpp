// maze problem
// http://poj.org/problem?id=3984

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

const int N = 5;

struct Pos {
    int row, col; // position of current point
    int indFrom; // index of input point

    Pos(int x, int y, int f) : row(x), col(y), indFrom(f) {}
};


//int main(int argc, char const *argv[])
//{
//    vector<vector<int> > maze(N, vector<int>(N, 0));
//    vector<vector<bool> > visited(N, vector<bool>(N, false));
//    for (int i = 0; i < N; ++i){
//        for (int j = 0; j < N; ++j)
//            cin >> maze[i][j];
//    }
//    vector<Pos> arrQueue;
//    arrQueue.push_back(Pos(0, 0, -1));
//    visited[0][0] = true;
//    int head = 0, tail = 1;
//
//    while (head != tail){
//        Pos cur = arrQueue[head];
//        if (cur.row == N - 1 && cur.col == N - 1){
//            break;
//        }else{
//            if (cur.row - 1 >= 0 && !maze[cur.row - 1][cur.col] && !visited[cur.row - 1][cur.col]){
//                arrQueue.push_back(Pos(cur.row - 1, cur.col, head));
//                visited[cur.row - 1][cur.col] = true;
//                tail++;
//            }
//            if (cur.row + 1 <= N - 1 && !maze[cur.row + 1][cur.col] && !visited[cur.row + 1][cur.col]){
//                arrQueue.push_back(Pos(cur.row + 1, cur.col, head));
//                visited[cur.row + 1][cur.col] = true;
//                tail++;
//            }
//            if (cur.col - 1 >= 0 && !maze[cur.row][cur.col - 1] && !visited[cur.row][cur.col - 1]){
//                arrQueue.push_back(Pos(cur.row, cur.col - 1, head));
//                visited[cur.row][cur.col - 1] = true;
//                tail++;
//            }
//            if (cur.col + 1 <= N - 1 && !maze[cur.row][cur.col + 1] && !visited[cur.row][cur.col + 1]){
//                arrQueue.push_back(Pos(cur.row, cur.col + 1, head));
//                visited[cur.row][cur.col + 1] = true;
//                tail++;
//            }
//        }
//        head++;
//    }
//    // use a stack to store the path.
//    stack<int> index;
//    for (int i = head; i != -1;){
//        index.push(i);
//        i = arrQueue[i].indFrom;
//    }
//
//    // output
//    while (!index.empty()){
//        cout << "(" << arrQueue[index.top()].row << ", " << arrQueue[index.top()].col << ")" << endl;
//        index.pop();
//    }
//
//    return 0;
//}
