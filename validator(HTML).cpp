#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{

	string math;
	string::iterator it = math.begin();

	getline(cin, math);

	if (math.find_first_not_of("1234567890()+-*/") == -1) {
		string num1, num2;
		int chis1, chis2, pos1, pos2;

		while (math.find("*") != -1) {
			it = math.begin();
			num1.clear();
			num2.clear();

			while (*it != '*') {
				it++;
			}
			it--;
			while (*it >= 48 && *it <= 57) {
				num1.push_back(*it);
				if (it == math.begin()) {
					break;
				}
				it--;
			}
			reverse(num1.begin(), num1.end());
			pos1 = distance(math.begin(), it);
			while (*it != '*') {
				it++;
			}
			it++;
			while (*it >= 48 && *it <= 57) {
				num2 += *it;
				if (it + 1 == math.end()) {
					break;
				}
				it++;
			}
			pos2 = distance(math.begin(), it);


			chis1 = stoi(num1);
			chis2 = stoi(num2);
			string temp = to_string(chis1 * chis2);

			bool flag = false;
			int multiplier = 0;
			if (pos1 != 0) {
				pos1++;
				flag = true;
			}
			if (pos2 + 1 == math.length()) {
				pos2++;
			}
			else {
				if (flag) {
					pos2 -= 2;
				}
			}
			math.replace(pos1, pos2, temp);
		}
		//	cout << math<<"\n";


		while (math.find("/") != -1) {
			it = math.begin();
			num1.clear();
			num2.clear();


			while (*it != '/') {
				it++;
			}
			it--;
			while (*it >= 48 && *it <= 57) {
				num1.push_back(*it);
				if (it == math.begin()) {
					break;
				}
				it--;
			}
			reverse(num1.begin(), num1.end());
			pos1 = distance(math.begin(), it);
			while (*it != '/') {
				it++;
			}
			it++;
			while (*it >= 48 && *it <= 57) {
				num2 += *it;
				if (it + 1 == math.end()) {
					break;
				}
				it++;
			}
			pos2 = distance(math.begin(), it);


			chis1 = stoi(num1);
			chis2 = stoi(num2);
			string temp = to_string(chis1 / chis2);

			bool flag = false;
			int multiplier = 0;
			if (pos1 != 0) {
				pos1++;
				flag = true;
			}
			if (pos2 + 1 == math.length()) {
				pos2++;
			}
			else {
				if (flag) {
					pos2 -= 2;
				}
			}
			math.replace(pos1, pos2, temp);
		}
		//		cout << math;

		while (math.find("+") != -1 || math.find("-")!=-1) {
			it = math.begin();
			num1.clear();
			num2.clear();

			string temp;
			temp.clear();
				if (math.find("+") < math.find("-") && math.find("+") != -1 || math.find("-")==-1) {
					while (*it != '+') {
						it++;
					}
					it--;
					while (*it >= 48 && *it <= 57) {
						num1.push_back(*it);
						if (it == math.begin()) {
							break;
						}
						it--;
					}
					reverse(num1.begin(), num1.end());
					pos1 = distance(math.begin(), it);
					while (*it != '+') {
						it++;
					}
					it++;
					while (*it >= 48 && *it <= 57) {
						num2 += *it;
						if (it + 1 == math.end()) {
							break;
						}
						it++;
					}
					pos2 = distance(math.begin(), it);


					chis1 = stoi(num1);
					chis2 = stoi(num2);
					temp = to_string(chis1 + chis2);
					bool flag = false;
					int multiplier = 0;
					if (pos1 != 0) {
						pos1++;
						flag = true;
					}
					if (pos2 + 1 == math.length()) {
						pos2++;
					}
					else {
						if (flag) {
							pos2 -= 2;
						}
					}
					math.replace(pos1, pos2, temp);

				}
				it = math.begin();
				num1.clear();
				num2.clear();
				if(math.find("+") > math.find("-") && math.find("-") != -1 ){//|| math.find("+") == -1){
					while (*it != '-') {
						it++;
					}
					it--;
					while (*it >= 48 && *it <= 57) {
						num1.push_back(*it);
						if (it == math.begin()) {
							break;
						}
						it--;
					}
					reverse(num1.begin(), num1.end());
					pos1 = distance(math.begin(), it);
					while (*it != '-') {
						it++;
					}
					it++;
					while (*it >= 48 && *it <= 57) {
						num2 += *it;
						if (it + 1 == math.end()) {
							break;
						}
						it++;
					}
					pos2 = distance(math.begin(), it);


					chis1 = stoi(num1);
					chis2 = stoi(num2);
					temp = to_string(chis1 - chis2);

					bool flag = false;
					int multiplier = 0;
					if (pos1 != 0) {
						pos1++;
						flag = true;
					}
					if (pos2 + 1 == math.length()) {
						pos2++;
					}
					else {
						if (flag) {
							pos2 -= 2;
						}
					}
					math.replace(pos1, pos2, temp);
				}
		

		}
		//cout << math;

		cout << math;

	}
	else {
		cout << "\nIncorrect input";
	}
}
