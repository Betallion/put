#define _HAS_CXX17 1
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iomanip>
using namespace std;
using namespace std::chrono;
using namespace std::filesystem;

vector<vector<int>> am_to_al(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    vector<vector<int>> adjacencylist;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                adjacencylist[i].push_back(j);
            }
        }
    }
    return adjacencylist;
}


void remove_edge(vector<vector<int>> &adjlist, int x, int y)
{
    for (int i = 0; i < adjlist[x].size(); i++)
    {
        if (adjlist[x][i] == y)
        {
            swap(adjlist[x][i], adjlist[x][adjlist[x].size() - 1]);
            adjlist[x].pop_back();
            break;
        }
    }
    for (int i = 0; i < adjlist[y].size(); i++)
    {
        if (adjlist[y][i] == x)
        {
            swap(adjlist[y][i], adjlist[y][adjlist[y].size() - 1]);
            adjlist[y].pop_back();
            break;
        }
    }
}

void add_edge(vector<vector<int>> &adjlist, int x, int y)
{
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
}

int dfs(vector<vector<int>> &adjlist, int start, vector<bool> &visited)
{
    visited[start] = true;
    int n = 0;
    for (int i = 0; i < adjlist[start].size(); i++)
    {
        if (visited[i] == false)
        {
            n += dfs(adjlist, i, visited);
        }
    }
    return n;
}

bool bridge(vector<vector<int>> &adjlist, int x, int y)
{
    int size = adjlist.size();
    int nr = 0;
    int na = 0;
    vector<bool> visited;
    remove_edge(adjlist, x, y);
    visited = vector<bool>(size + 1, false);
    nr = dfs(adjlist, x, visited);
    add_edge(adjlist, x, y);
    visited = vector<bool>(size + 1, false);
    na = dfs(adjlist, x, visited);
    if (nr == na)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void euler(vector<vector<int>> &adjlist, int start, vector<int> &visited)
{
    visited.push_back(start);
    if (adjlist[start].size() == 0)
    {
        return;
    }
    if (adjlist[start].size() == 1)
    {
        int v = adjlist[start][0];
        remove_edge(adjlist, start, v);
        euler(adjlist, v, visited);
        return;
    }
    for (int i = 0; i < adjlist[start].size(); i++)
    {
        if (bridge(adjlist, start, adjlist[start][i]) == true)
        {
            remove_edge(adjlist, start, adjlist[start][i]);
            euler(adjlist, adjlist[start][i], visited);
            return;
        }
    }

}

vector<int> eulerian_cycle(vector<vector<int>> &adjlist)
{
    vector<int> deg(adjlist.size(), 0);
    for (int i = 0; i < adjlist.size(); i++)
    {
        deg[i] += adjlist[i].size();
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            deg[adjlist[i][j]] += 1;
        }
    }
    vector<int> visited;
    for (int i = 0; i < deg.size(); i++)
    {
        if (deg[i] % 2 != 0)
        {
            cout << "nie ma cyklu Eulera" << endl;
            return visited;
        }
    }
    
    euler(adjlist, 0, visited);
    return visited;
}


int main(int argc, char* argv[])
{
    string f = argv[1];
    string nas = argv[2];
    string num = argv[3];
    ifstream file(f.c_str());
    string line;
    vector<vector<int>> matrix;
    while(getline(file, line))
    {
        vector<int> row;
        for (int i : line)
        {
            if (i != ' ')
            {
                row.push_back(i);
            }
        }
        matrix.push_back(row);
    }
    vector<vector<int>> adjlist = am_to_al(matrix);

    auto start = high_resolution_clock::now();
    vector<int> result = eulerian_cycle(adjlist);
    auto stop = high_resolution_clock::now();
	duration<double> duration = stop - start;
    double dd = duration.count();
    path dir = current_path();
	string dirstr = dir.string();
	string filename = dirstr + "/times/" + nas + "_euler_times.txt";
    fstream dur;
    dur.open(filename.c_str(), fstream::out | fstream::app);
	//create << std::fixed << std::setprecision(8) << ddc << endl;
	dur << num << dd << endl;
	dur.close();
    return 0;
}