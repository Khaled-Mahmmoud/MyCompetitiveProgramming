```cpp
bool isLeap(int y)
{
    return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}
string dayOfTheWeek(int day, int month, int year)
{
    vector<int> md = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<string> show{ "Friday", "Saturday", "Sunday", "Monday",
                         "Tuesday", "Wednesday", "Thursday" };
    int idx = 6;
    for (int y = 1971; y < year; y++)
        idx += (isLeap(y) ? 366 : 365);
    for (int m = 1; m < month; m++)
        idx += (isLeap(year) && m == 2 ? 29 : md[m]);
    idx += day;
    return show[idx % 7];
}
```
