//#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> get_high_low_jumps(vector<int> heights) {
    int num_high = 0;
    int num_low = 0;
    int jump = 0;
    int negatives = 0;
    int one_ocurrences = 0;

    for (int i = 0; i < heights.size() - 1; i++) {

        jump = heights.at(i + 1) - heights.at(i);

        if (jump == 0)
            continue;

        if (jump < 0) {
            negatives++;
            num_low++;
        } else if (jump == 1) {
            one_ocurrences++;
        } else {
            num_high++;
        }
    }

    if( negatives > 0 )
        num_high = num_high + one_ocurrences;
    else
        num_low = num_low + one_ocurrences;

    if (num_high == 0)
        return make_pair(num_low, num_high);
    else
        return make_pair(num_high, num_low);
}

int main() {

    int n;
    vector<int> heights;
    vector<pair<int, int>> results;
    string input_line;

    cin >> n;

    for (int i = 0; i < n; i++) {
        fflush(stdin);  //FLUSHING STDIN
        getline(cin, input_line);

        getline(cin, input_line);

        stringstream sep(input_line);
        string height;

        heights.clear();
        while (getline(sep, height, ' ')) {
            heights.push_back(stoi(height));
        }

        auto jumps = get_high_low_jumps(heights);

        results.push_back(jumps);

    }

    for (int j = 0; j < results.size(); j++)
        cout << "Case " << j + 1 << ": " << results.at(j).first << " " << results.at(j).second << endl;
    cout << endl;
    return EXIT_SUCCESS;
}