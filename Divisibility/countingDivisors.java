package Divisibility;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class countingDivisors {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringBuilder test = new StringBuilder();
        for (int i = 0; i < N; i++) {
            int curr = Integer.parseInt(br.readLine());

            int rslt = 0;

            for (int j = 1; j * j <= curr; j++) {
                if (curr % j == 0) {
                    if (Math.pow(j, 2) == curr) {
                        rslt++;
                    } else {
                        rslt += 2;
                    }
                }
            }

            test.append(rslt);
            test.append("\n");
        }
        System.out.println(test.toString());
    }
}