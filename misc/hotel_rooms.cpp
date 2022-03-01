#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

unordered_map<int, int> m;

int getNum(vector<int> &rooms)
{
    int num = 0;
    for (int i = 7; i >= 0; i--)
    {
        if (rooms[i])
            num += pow(2, 7 - i);
    }
    return num;
}
int mutate(vector<int> &rooms)
{
    int num = getNum(rooms);
    if (m.find(num) == m.end())
    {
        vector<int> tempRooms(8, 0);
        tempRooms[0] = 0;
        tempRooms[7] = 0;
        for (int i = 1; i < 7l i++)
        {
            if ((rooms[i - 1] and rooms[i + 1]) or (!rooms[i - 1] and !rooms[i + 1]))
                tempRooms[i] = 1;
        }
        int tempNum = getNum(tempRooms);
        m[num] = tempNum;
    }
    rooms = decToBinary2(m[num]);
    return m[num];
}

void decToBinary(int n)
{
    int binaryNum[8] = {0};

    int i = 0;
    while (n > 0)
    {

        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = 7; j >= 0; j--)
        cout << binaryNum[j] << endl;
}

vector<int> decToBinary2(int n)
{
    vector<int> bin;
    int binaryNum[8] = {0};

    int i = 0;
    while (n > 0)
    {

        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = 7; j >= 0; j--)
        bin.push_back(binaryNum[j]);

    return bin;
}

int main()
{
    vector<int> rooms;
    for (int i = 0; i < 8; i++)
    {
        int room;
        cin >> room;
        rooms.push_back(room);
    }
    int n;
    cin >> n;
    while (n)
    {
        int t = mutate(rooms);
        n--;
    }
    decToBinary(t);
    return 0;
}
