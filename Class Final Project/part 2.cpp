//part 2 of the project
//brute force method implemented first
//then 2 new approach have been introduced
//final changes and comments have been made as we progress
//all the functions and how they work will be explained in detail in the project report "part 2"

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

// 1) brute force method
// we will try to iterate through every element
// and with the help of another loop
// we will check the sum equals to the target variable
// time complexity of order O(n^2)
// this will be worst order time because we have for loop inside for loop
// this will result in second for loop iterating for (n-i) times for every (i) of firsst for loop

vector<vector<int>> brute_force_method(vector<int>& vrr, int target)
{
	int n = vrr.size();
	vector<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		vector<int> pairVec;
		for (int j = i + 1; j < n; j++)
		{
			if (vrr[i] + vrr[j] == target)
			{
				pairVec.push_back(i);
				pairVec.push_back(j);
			}
		}

		res.push_back(pairVec);
	}

	if (res.size() == 0) {
		cout << "no pair available in this set of number ";
		res.push_back({ -1,-1 });
	}
	cout << "brute method res size " << res.size();
	return res;
};

// this can be interpreted as an average run time case since it will be around O(nLogn) order
// we will traverse in the same vector to check if two elements add upto the target element
// for this we will need to make the vector sorted first
// for sorting we will use the 
// after sorting the index for all numbers will generally change (except when already sorted array given)
// this will result in different output of indices for every

vector<vector<int> > avg_case_solution(vector<int>& vrr, int target)
{
	int i = 0, j = vrr.size() - 1;
	vector<vector<int>> res;
	sort(vrr.begin(), vrr.end());
	while (i < j) {
		vector<int> pairVec;
		int sum = vrr[i] + vrr[j];

		if (sum == target)
		{
			pairVec.push_back(i);
			pairVec.push_back(j);
			res.push_back(pairVec);
			j--;
			continue;
		}


		if (sum > target)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	cout << "avg method res size " << res.size();
	return res;
};

// now let's perform the most efficient algorithm for finding the pairs for given target
// we will be using hasp map or keep count to find our pairs of number that add upto the target
//this is most efficient because it will have time complexity of order O(n) (linear time)

vector<int> efficicent_method(vector<int>& vrr, int target) {
	std::map<int, int> map1;
	std::map<int, int>::const_iterator found;
	vector<int> res;
	for (int i = 0; i < vrr.size(); i++) {
		int complement = target - vrr[i];
		found = map1.find(complement);

		if (found != map1.end()) {
			res.push_back(found->second);
			res.push_back(i);
		}

		map1.insert(pair<int, int>(vrr[i], i));
	}
	cout << "efficient method res size " << res.size();
	return res;

};

vector<int> vrr;

int main()
{
	srand(time(NULL));
	clock_t time_1, time_2, time_3;
	float time;

	int n, t;
	cout << "enter size for vector" << endl;
	cin >> n;														//you can create an array of length of your choice
	cout << "enter data for vector according to size" << endl;
	for (int i = 0; i < n; i++)
	{																//input numbers for data set or numbers in the vector
		int input;
		cin >> input;
		vrr.push_back(input);
	}

	vector<int> copy = vrr;
	cout << endl;

	cout << "enter target" << endl;									//enter the target or the number required for sum
	cin >> t;

	time_1 = clock();
	vector<vector<int>> res = brute_force_method(vrr, t);			//call function for brute force solution function
	time_1 = clock() - time_1;
	cout << "runtime for brute force method is: " << (time_1 * 10e6) << endl;
	cout << "res.size in brute after calling method " << res.size() << endl;
	if (res.size() == 0) {
		cout << "Not exist!" << endl;								//condition if there is no solution
	}
	for (int i = 0; i < res.size(); i++) {							//we will output the index of the pairs whose sum adds upto the target
		for (int j = 0; j < res[i].size(); j++)						//the output is in drawn from a vector that has two columns but can have as many rows as the "return res" produces
			cout << res[i][j] << " ";
		cout << endl;

	}
	cout << endl;
	time_2 = clock();
	res = avg_case_solution(vrr, t);			//call function for average time solution function
	time_2 = clock() - time_2;
	cout << "runtime for brute force method is: " << (time_2 * 10e6) << endl;
	if (res.size() == 0) {
		cout << "Not exist!" << endl;								//condition if there is no solution
	}
	for (int i = 0; i < res.size(); i++) {							//the output is in drawn from a vector that has two columns but can have as many rows as the "return res" produces
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";

		cout << endl;
	}
	cout << endl;
	time_3 = clock();
	vector<int>  result = efficicent_method(copy, t);					//call function for effecient time solution function
	time_3 = clock() - time_3;											//since the retrun for this function is not a vector of vector
	cout << "runtime for brute force method is: " << (time_3 * 10e6) << endl;
	if (result.size() == 0) {
		cout << "Not exist!" << endl;								//condition if there is no solution
	}
	for (int i = 0; i < result.size(); i += 2) {						//we can just return all the index of the pairs one after another
		cout << "(" << result[i] << "," << result[i + 1] << ")" << endl;	//we have added a for loop to make it seem like they are tuples
	}

}

