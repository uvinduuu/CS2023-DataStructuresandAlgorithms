#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);

    for (const auto& query : queries) { //running through each row
        int start = query[0] - 1; //starting index needed to add the value
        int end = query[1]; //last index needed to add the value
        int valueToAdd = query[2]; //value needed to add to the element

        arr[start] += valueToAdd; //adding value to the starting element
        arr[end] -= valueToAdd; //substracting value from the last index
    }

    long maxVal = 0; //initial maximum value as zero
    long sum = 0; //initial cumulative sum as zero

    for (int i = 0; i < n; ++i) { //calculating the cumalitive sum to get the maximum value more time effectively
        sum += arr[i];
        maxVal = max(maxVal, sum); //getting the maximum value between maxVal and sum
    }
    cout<<maxVal; //printing the maxVal

    return maxVal;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
