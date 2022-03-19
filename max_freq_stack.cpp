//895: Maximum frequency stack
//we are using map of stack as our data structure
class FreqStack {
public:
    map< int, stack<int>, greater<int> >mp;
    unordered_map<int, int>um;
    void push(int val) {
        um[val]++;
        mp[um[val]].push(val);
    }
    
    int pop() {
        int x = mp.begin()->second.top();
        mp.begin()->second.pop();
        if(mp.begin()->second.empty()){
            mp.erase(mp.begin()->first);
        }
        um[x]--;
        return x;
    }
};