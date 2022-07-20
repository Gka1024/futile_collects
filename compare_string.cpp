bool cmpsize(int a, int b)
{
    string astring = to_string(a); // 121
    string bstring = to_string(b); // 122

    return astring + bstring > bstring + astring;
    // 121122, 122121 비교 -> 122121이 더 큼
}
