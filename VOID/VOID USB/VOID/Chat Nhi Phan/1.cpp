int lower = 1, upper = n;
        while (lower < upper) {
            int mid = (lower + upper) / 2;
            if (s[mid] - s[i - 1] >= k) {
                upper = mid;
            }
            else {
                lower = mid + 1;
            }
        }