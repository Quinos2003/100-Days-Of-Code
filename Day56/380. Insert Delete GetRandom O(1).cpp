class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> arr;

    RandomizedSet() {
        return;
    }
    bool insert(int val) {
        if(mp.count(val)) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }
    bool remove(int val) {
        if(mp.count(val)){
            int idx = mp[val];
            int last_val = arr.back();
            arr[idx] = last_val;
            arr.pop_back();
            mp[last_val] = idx;
            mp.erase(val);
            return true;
        }
        return false;
    }
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// class RandomizedSet {
// public:
// vector<int> randomSet;
//     RandomizedSet() {
//         ios_base::sync_with_stdio(false); 
//     }
    
//     bool insert(int val) {
//         if(find(randomSet.begin(),randomSet.end(),val) == randomSet.end()){
//             randomSet.push_back(val);
//             return true;
//         }
//         else
//             return false;
//     }
    
//     bool remove(int val) {
//         auto it = find(randomSet.begin(),randomSet.end(),val);
//         if(it != randomSet.end()){
//             randomSet.erase(it);
//             return true;
//         }
//         else return false;
//     }
    
//     int getRandom() {
//         return randomSet[rand()%randomSet.size()];
//     }
// };

// /**
//  * Your RandomizedSet object will be instantiated and called as such:
//  * RandomizedSet* obj = new RandomizedSet();
//  * bool param_1 = obj->insert(val);
//  * bool param_2 = obj->remove(val);
//  * int param_3 = obj->getRandom();
//  */