#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void insertionSort2(int n, vector<int>& arr) {
    for (int i = 1; i < n; i++) { //starting from index=1 and iterate till the final index=n-1
        int temp = arr[i]; //storing the current elemant's value in a temporary variable
        int a; //initiating a gobal variable
        for (a = i - 1; a >= 0 && temp < arr[a]; a--) { //checking whether adjacent elements in the left are greater than the checking elemant, and decrementing the index
            arr[a + 1] = arr[a]; //storing the bigger value at the right index
        }
        arr[a + 1] = temp; //storing the bigger value at the right index ; when checking elemant is greater than the left element
        for (int k = 0; k < n; k++) { //printing the array
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort2(n, arr);

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
