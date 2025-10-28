// IN the case of shortest path problems
//there are some dependecy problems , which just cant be solve by normal dijkstra , dijkstra with some dependency on previous nodes problems
//Ex : 
// 1) https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
// here we have to find the number of ways to reach the destination in the shortest time, but here we cant just update a count variable when we reach the destination node
// because there can be multiple ways to reach a node(with same minimum time) before destination node that is in the path of destination node so automatically there will be multiple ways to reach the destination node, so we have to keep track of the number of ways to reach each node in the minimum time
// so we use a count vector to store the number of ways to reach each node in the minimum time
// and when we find a shorter way to reach a node, we update the count of that node to be the count of the current node
// and when we find another way to reach a node in the same minimum time, we add the count of the current node to the count of that node

// 2) https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
//here we have to find the cheapest price to reach the destination with at most k stops, so we have to keep track of the number of stops taken to reach each node
// so inside price vector we also keep track of stops (vector<vector<int>> price(n,vector<int> (k+2,INT_MAX)); k= no. of stops + src + dest) to store the best price with certian number of stops taken to reach each node
