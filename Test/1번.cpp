#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lotteries) {

    int answer = 0;
    double BestPercent = -1;
    double BestPrice = -1;
    double TempPercent;
    double TempPrice;

    for (int i = 0; i < lotteries.size(); i++) {
        double a = lotteries[i][0];
        double b = lotteries[i][1] + 1;
        if (a < b) TempPercent = a / b;
        else TempPercent = 1;

        TempPrice = lotteries[i][2];

        if (TempPercent > BestPercent) {
            BestPercent = TempPercent;
            BestPrice = lotteries[i][2];
            answer = i + 1;
        }
        else if (TempPercent == BestPercent) {
            if (TempPrice > BestPrice) {
                BestPrice = TempPrice;
                answer = i + 1;
            }
        }
    }

    return answer;
}