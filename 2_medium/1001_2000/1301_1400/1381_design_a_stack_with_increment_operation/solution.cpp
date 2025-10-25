class CustomStack {
    vector<int> stack;
    int max_size;
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
    }

    void push(int x) {
        if (stack.size() != max_size) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.size() == 0) {
            return -1;
        }
        int res = stack[stack.size() - 1];
        stack.pop_back();
        return res;
    }

    void increment(int k, int val) {
        for (int i{0}; i < min((int) stack.size(), k); ++i) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
