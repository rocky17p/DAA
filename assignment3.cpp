#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class Item {
public:
    ll weight;
    ll value;

    Item(ll w, ll v) {
        weight = w;
        value = v;
    }
};

bool compare(Item &a, Item &b) {
    return (double)a.value / a.weight >
           (double)b.value / b.weight;
}

double fractionalKnapsack(int n, ll capacity,
                          vector<ll>& wt,
                          vector<ll>& val) {

    vector<Item> items;

    for(int i = 0; i < n; i++) {
        items.push_back(Item(wt[i], val[i]));
    }

    // Highest value/weight ratio first
    sort(items.begin(), items.end(), compare);

    double ans = 0;

    for(int i = 0; i < n; i++) {

        // Entire item fits
        if(items[i].weight <= capacity) {
            capacity -= items[i].weight;
            ans += items[i].value;
        }

        // Only a fraction fits
        else {
            ans += (double)items[i].value *
                   capacity / items[i].weight;

            capacity = 0;
            break;
        }
    }

    return ans;
}

int main() {

    int n;
    ll capacity;

    cin >> n;
    cin >> capacity;

    vector<ll> wt(n);
    vector<ll> val(n);

    for(int i = 0; i < n; i++)
        cin >> wt[i];

    for(int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Maximum value = "
         << fractionalKnapsack(n, capacity, wt, val)
         << endl;

    return 0;
}
