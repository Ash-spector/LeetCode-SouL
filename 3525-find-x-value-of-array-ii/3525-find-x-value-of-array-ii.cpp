class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;

            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int k;
    int size;

    Node merge(Node &a, Node &b) {
        Node res;

        // Product of entire segment
        res.prod = (1LL * a.prod * b.prod) % k;

        // Prefixes completely inside a
        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        // Prefixes which contain all of a
        // and some prefix of b
        for (int r = 0; r < k; r++) {

            int newRem = (1LL * a.prod * r) % k;

            res.cnt[newRem] += b.cnt[r];
        }

        return res;
    }

    Node makeNode(int value) {
        Node res;

        int rem = value % k;

        res.prod = rem;
        res.cnt[rem] = 1;

        return res;
    }

    void update(int index, int value, vector<Node>& tree) {

        int pos = index + size;

        tree[pos] = makeNode(value);

        pos /= 2;

        while (pos > 0) {

            tree[pos] = merge(
                tree[pos * 2],
                tree[pos * 2 + 1]
            );

            pos /= 2;
        }
    }

    Node query(int start, vector<Node>& tree, int n) {

        int l = start + size;
        int r = n + size;

        // Empty segment
        Node leftResult;
        Node rightResult;

        while (l < r) {

            if (l & 1) {

                leftResult = merge(leftResult, tree[l]);

                l++;
            }

            if (r & 1) {

                --r;

                rightResult = merge(tree[r], rightResult);
            }

            l /= 2;
            r /= 2;
        }

        return merge(leftResult, rightResult);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->k = k;

        int n = nums.size();

        // Power of 2 >= n
        size = 1;

        while (size < n)
            size *= 2;

        vector<Node> tree(2 * size);

        // Build leaves
        for (int i = 0; i < n; i++) {
            tree[size + i] = makeNode(nums[i]);
        }

        // Build tree
        for (int i = size - 1; i >= 1; i--) {

            tree[i] = merge(
                tree[i * 2],
                tree[i * 2 + 1]
            );
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(index, value, tree);

            // Query nums[start ... n-1]
            Node res = query(start, tree, n);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};