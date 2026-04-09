Try opening the file directly — click the **concat-viz** link/attachment above to open it in your browser.

If that doesn't work, here's a quick static visual of what the problem asks:

```
nums = [1, 4, 1, 2]
         ↓  ↓  ↓  ↓
ans  = [1, 4, 1, 2, | 1, 4, 1, 2]
        [0][1][2][3]  [4][5][6][7]
         ans[i]         ans[i+n]
```

**Task:** Just glue `nums` to itself. `ans[i] = nums[i]` and `ans[i+n] = nums[i]`.

> In Python it's literally `return nums + nums` — one line.