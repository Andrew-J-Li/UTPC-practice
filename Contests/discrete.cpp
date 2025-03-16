#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cout << fixed << setprecision(10);

    while (t--) {
        int n, l;
        cin >> n >> l;
        vector<double> flags(n);
        for (int i = 0; i < n; ++i) {
            cin >> flags[i];
        }

        int left_passed = 0, right_passed = 0;
        double current_left = 0.0, current_right = l;
        double time = 0.0;
        double left_speed = 1.0, right_speed = 1.0;

        while (current_left < current_right) {
            double next_left_flag = (left_passed < n) ? flags[left_passed] : l;
            double next_right_flag = (right_passed < n) ? flags[n - 1 - right_passed] : 0.0;

            double time_to_left = (next_left_flag - current_left) / left_speed;
            double time_to_right = (current_right - next_right_flag) / right_speed;
            double delta_t = min(time_to_left, time_to_right);

            double distance = current_right - current_left;
            double combined_speed = left_speed + right_speed;
            double time_meet = distance / combined_speed;

            if (time_meet <= delta_t) {
                time += time_meet;
                break;
            } else {
                time += delta_t;
                current_left += left_speed * delta_t;
                current_right -= right_speed * delta_t;

                if (delta_t == time_to_left) {
                    left_passed++;
                    left_speed += 1.0;
                }
                if (delta_t == time_to_right) {
                    right_passed++;
                    right_speed += 1.0;
                }
            }
        }

        cout << time << '\n';
    }

    return 0;
}