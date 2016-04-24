/*
虽说迭代器是要用迭代的方法，但是我们可以强行使用递归来解，怎么个强行法呢，就是我们使用一个队列queue，在构造函数的时候就利用迭代的方法把这个嵌套链表全部压平展开，然后在调用hasNext()和next()就很简单了：
*/
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        make_queue(nestedList);
    }

    int next() {
        int t = q.front(); q.pop();
        return t; 
    }

    bool hasNext() {
        return !q.empty();
    }
    
private:
    queue<int> q;
    void make_queue(vector<NestedInteger> &nestedList) {
        for (auto a : nestedList) {
            if (a.isInteger()) q.push(a.getInteger());
            else make_queue(a.getList());
        }
    }
};
