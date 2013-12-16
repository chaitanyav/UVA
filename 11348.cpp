#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>

int main(int argc, char *argv[]) {
	int numTestCases, numFriends, numStamps, stamp, testCase, friendc, uniqueStamps;
	std::map<int, std::map<int, int> > stampCountByFriend;
	std::map<int, int> countByStamp;
	testCase = 0;

	std::cin >> numTestCases;
	while(numTestCases > 0) {
		++testCase;
		scanf("%d", &numFriends);
		stampCountByFriend.clear();
		countByStamp.clear();
		friendc = 0;
		uniqueStamps = 0;

		while(numFriends > 0) {
			scanf("%d", &numStamps);
			friendc++;
			while(numStamps > 0) {
				scanf("%d", &stamp);

				if(stampCountByFriend.find(friendc) == stampCountByFriend.end()) {
					stampCountByFriend[friendc][stamp] = 1;
					if(countByStamp.find(stamp) != countByStamp.end()) {
						countByStamp[stamp] = countByStamp[stamp] + 1;
					}
				} else {
					if(stampCountByFriend[friendc].find(stamp) == (stampCountByFriend[friendc]).end()) {
						stampCountByFriend[friendc][stamp] = 1;
						if(countByStamp.find(stamp) != countByStamp.end()) {
							countByStamp[stamp] = countByStamp[stamp] + 1;
						}
					} else {
						stampCountByFriend[friendc][stamp] = stampCountByFriend[friendc][stamp] + 1;
					}
				}
				if(countByStamp.find(stamp) == countByStamp.end()) {
					countByStamp[stamp] = 1;
				}
				numStamps--;
			}
			numFriends--;
		}


		for(std::map<int, int>::iterator mit = countByStamp.begin(); mit != countByStamp.end(); mit++) {
			if(mit->second == 1) {
				uniqueStamps++;
			}
		}

		printf("Case %d:", testCase);
		for(int index = 1; index <= friendc; index++) {
			double total = 0.0;
			for(std::map<int, int>::iterator mit = (stampCountByFriend[index]).begin(); mit != (stampCountByFriend[index]).end(); mit++) {
				if(countByStamp[mit->first] == 1) {
					total++;
				}
			}			
			if(uniqueStamps == 0) {
				printf(" %.6f%%", 100.0 / friendc);
			} else {
				printf(" %.6f%%", 100.0 * (total / uniqueStamps));
			}

		}
		printf("\n");
		numTestCases--;
	}

	return 0;
}