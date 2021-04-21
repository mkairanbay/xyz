/**
 * The goal of this program is to find a
 * straight route between the cars, that crosses the least number of cars. 
 * The route can’t be in front of the first car or behind the last car. 
 * Assume there’s a fixed gap between the car in front
 * and behind that you don’t have to introduce in the code.
 * 
 * @author Magzhan Kairanbay
 * 
 * @version 1.0.0
 */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/**
 * This function read from input n lines.
 * First number of each line represents the number of cars in that line,
 * followed by the car lengthes.
 * 
 * @return vector of car lengthes
 */ 
vector<vector<int>> readCarLengthes() {
    
    // initialize and read the number of lines
    int n;
    cin >> n;
    
    vector<vector<int>> carLength;
    for (int i = 0; i < n; i++) {
        // read number of cars in each line
        int m;
        cin >> m;
        
        // car length
        vector<int> cars;
        // for each line read car lengthes
        for (int j = 0; j < m; j++) {
            int carLength;
            cin >> carLength;
            cars.push_back(carLength);
        }
        carLength.push_back(cars);
    }
    
    return carLength;
}

/**
 * This function finds the maximum car length sum among all lines.
 * 
 * @param vector of car lengthes
 * 
 * @return max sum among all lines
 */ 
int findMaxSum(vector<vector<int>> carLength) {
    
    // find the highest sum of car lengthes among all lines
    int maxSum = 0;
    for (int i = 0; i < carLength.size(); i++) {
        // sum of car lengthes for each line
        int sum = 0;
        for (int j = 0; j < carLength[i].size(); j++) {
            sum += carLength[i][j];
        }
        // find maximum sum among all lines
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    
    return maxSum;
}

/**
 * This function finds the number of crosses of line with cars.
 * 
 * @param vector of car lengthes
 * 
 * @return the number of crosses of line with cars
 */ 
int findNumberOfCrosses(vector<vector<int>> carLength) {
    
    int maxSum = findMaxSum(carLength);
    
    // we assume that the answer is very large number
    int ans = INT_MAX;
    
    // iterate from 1 till the max sum
    for (int ind = 1; ind < maxSum; ind++) {
        // counts the number of tangents for each row
        int totalCnt = 0;
        for (int i = 0; i < carLength.size(); i++) {
            int j = 0;
            int sum = ind;
            // counter which identifies whether the car is tangent to the line
            int cnt = 0;
            while (j < carLength[i].size()) {
                sum -= carLength[i][j];
                // if the line crosses the car
                if (sum < 0) {
                    break;
                }
                // if the car is tangent to the line then increment counter
                if (sum == 0) {
                    cnt++;
                }
                j++;
            }
            // total number of cars which is tangent to the line
            totalCnt += cnt;
        }
        // total number of crosses
        int numberOfCrosses = carLength.size() - totalCnt;
        // find the minimum answer among all
        if (numberOfCrosses < ans) {
            ans = numberOfCrosses;
        }
    }
    
    return ans;
}

int main()
{
    
    vector<vector<int>> carLength = readCarLengthes();
    int numberOfCrosses = findNumberOfCrosses(carLength);
    cout << numberOfCrosses;

    return 0;
}
