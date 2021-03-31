// proj 3278, Catch that Cow
// http://poj.org/problem?id=3278

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int N, K;
const int MAXN = 100000;
vector<bool> visited(MAXN + 10, false); // if visited[i] = true, means i has been visited

struct Step {
    int pos;
    int steps;

    Step(int new_pos, int new_step) : pos(new_pos), steps(new_step) {}
};

queue<Step> q; // 

//int main(int argc, char const *argv[])
//{
//    cin >> N >> K;
//    q.push(Step(N, 0));
//    visited[N] = true; // start point
//
//    while (!q.empty()){
//        Step s = q.front();
//        if (s.pos == K){ // find the cow
//            cout << s.steps << endl;
//            return 0;
//        }else{
//            if (s.pos - 1 >= 0 && !visited[s.pos - 1]){
//                q.push(Step(s.pos - 1, s.steps + 1));
//                visited[s.pos - 1] = true;
//            }
//            if (s.pos + 1 <= MAXN && !visited[s.pos + 1]){
//                q.push(Step(s.pos + 1, s.steps + 1));
//                visited[s.pos + 1] = true;
//            }
//            if (s.pos * 2 <= MAXN && !visited[s.pos * 2]){
//                q.push(Step(s.pos * 2, s.steps + 1));
//                visited[s.pos * 2] = true;
//            }
//        }
//        q.pop(); // pop the current start point
//    }
//
//
//
//    return 0;
//}

