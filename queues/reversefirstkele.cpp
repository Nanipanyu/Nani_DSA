#include<iostream>
#include<queue>
using namespace std;

void revk(queue<int> &q,int k,int count=0){
    if(count==k){ //if kth ele return
        return;
    }
    int ele=q.front(); //storing front val
    q.pop(); //poping front val
    revk(q,k,count+1); //recursive call
    q.push(ele); //push the ele in reverse order while going back but one problem is the reverse elements get push in last (behind the ele which are not reversed)
}
    // Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
    revk(q,k); //reversing first k elements
    int qsize=q.size();
    for(int i=0;i<qsize-k;i++){ //to fix the problem of reverse elements getting pushed in end of queue behind elements which are not reversed , take the front ele and push it in back of queue(all the unreversed ele) this solves it.
        q.push(q.front());
        q.pop();
    }
    return q;
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    queue<int> res = modifyQueue(q, k);
    cout << "Queue after reversing first " << k << " elements: ";
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop();
    }
}
