## Commonly used libraries

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
```

## Speedup data IO

```cpp
static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
```

## m x n matrix

`m`: num of rows
`n`: num of cols
`r`: result

```
m n r
...
```

`0085.txt`:

```
4 5 6
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
5 6 4
1 1 1 0 1 1
1 0 1 1 1 0
1 1 1 1 0 1
1 0 1 0 1 1
1 1 0 1 1 0
```

`0085.cpp`:

```cpp
int maximalRectangle(vector<vector<char>>& matrix) {

    return matrix.size();
}

int main() {
    string sin;
    int row, col, rr, state;
    vector<vector<vector<char>>> vg={};
    vector<int> vr;

    ifstream fp;
    fp.open("0085.txt");

    while (getline(fp, sin, '\n')) {
        stringstream ss(sin);
        ss >> row >> col >> rr;
        vr.push_back(rr);
        vg.push_back({});
        for (int i=0; i<row; ++i) {
            getline(fp, sin, '\n');
            stringstream ss(sin);
            vg.back().push_back({});
            for (int j=0; j<col; ++j) {
                ss >> state;
                vg.back()[i].push_back('0'+state);
            }
        }
    }
    fp.close();

    printf("--- --- --- --- \n");
    printf("%s\t%s\t%s\t%s\n", "T","L", "√", "?");
    printf("--- --- --- --- \n");
    int line=1;
    for (int i=0; i<vr.size(); ++i) {
        int res = maximalRectangle(vg[i]);
        printf("%d\t%d\t%d\t%d\t\n", res==vr[i], line, vr[i], res);
        line += vg[i].size()+1;
    }

    return 0;
}
```