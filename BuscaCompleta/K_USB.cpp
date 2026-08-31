#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    int m;
    cin >> m;
    
    vector<long long> usb, ps2;
    
    
    for (int i = 0; i < m; ++i) {
        long long price;
        string type;
        cin >> price >> type;
        if (type == "USB")
            usb.push_back(price);
        else
            ps2.push_back(price);
    }
    
    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());
    
    long long equipped = 0, total = 0;
    size_t iusb = 0, ips2 = 0;
    
    // USB
    for (long long k = 0; k < a && iusb < usb.size() ; ++k) {
        total += usb[iusb];
        ++iusb;
        ++equipped;
    }
    
    // PS/2
    for (long long k = 0; k < b &&  ips2 < ps2.size(); ++k) {
        total += ps2[ips2];
        ++ips2;
        ++equipped;
    }
    
    // Computadores que dão suporte à ambas. Nesse caso, deve-se atentar-se ao fato de que é preciso escolher,
    // preferencialmente, os mouses com o menor preço. 
    for (long long k = 0; k < c; ++k) {
       bool haveUsb = iusb < usb.size();
        bool havePs2 = ips2< ps2.size();

        if (!haveUsb && !havePs2) break;               // Sobrou nada left

        if (haveUsb && havePs2) {                      // Quando ainda houverem tanto USB quanto PS/2
            if (usb[iusb] <= ps2[ips2]) {
                total += usb[iusb++];
            } else {
                total += ps2[ips2++];
            }
        } else if (haveUsb) {                          // Sobrou apenas USB 
            total += usb[iusb++];
        } else {                                       // Sobrou apenas PS/2 
            total += ps2[ips2++];
        }
        ++equipped;
        
    }
    
    cout << equipped << ' ' << total << '\n';
    return 0;
}