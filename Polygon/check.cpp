#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
using ll = long long;

struct Pencil
{
    int r, g, b;
    int index;
};

int getDiff(const Pencil &p1, const Pencil &p2)
{
    return max({abs(p1.r - p2.r), abs(p1.g - p2.g), abs(p1.b - p2.b)});
}

int getVibrancy(const vector<Pencil> &pencils)
{
    if (pencils.size() <= 1)
        return 0;

    // Tìm min, max cho mỗi thành phần R, G, B
    int minR = 255, maxR = 0;
    int minG = 255, maxG = 0;
    int minB = 255, maxB = 0;

    for (const Pencil &p : pencils)
    {
        minR = min(minR, p.r);
        maxR = max(maxR, p.r);
        minG = min(minG, p.g);
        maxG = max(maxG, p.g);
        minB = min(minB, p.b);
        maxB = max(maxB, p.b);
    }

    // Độ sặc sỡ là max của các khoảng cách
    int maxDiff = max({maxR - minR, maxG - minG, maxB - minB});
    return maxDiff;
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    // Đọc input
    int n = inf.readInt();
    int k = inf.readInt();

    // Kiểm tra ràng buộc
    if (k < 2 || k > n)
    {
        quitf(_fail, "Invalid constraints: k = %d not in range [2, %d]", k, n);
    }

    vector<Pencil> allPencils(n);
    for (int i = 0; i < n; ++i)
    {
        int r = inf.readInt();
        int g = inf.readInt();
        int b = inf.readInt();

        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        {
            quitf(_fail, "Invalid RGB value at pencil %d: (%d, %d, %d)", i + 1, r, g, b);
        }

        allPencils[i] = {r, g, b, i + 1};
    }

    // Đọc output của contestant
    int outputVibrancy = ouf.readInt();

    vector<int> selectedIndices;
    for (int i = 0; i < k; ++i)
    {
        int idx = ouf.readInt();

        // Check chỉ số hợp lệ
        if (idx < 1 || idx > n)
        {
            quitf(_wa, "Invalid pencil index: %d not in range [1, %d]", idx, n);
        }

        selectedIndices.push_back(idx);
    }

    // Kiểm tra xem đúng K chỉ số không
    if (selectedIndices.size() != k)
    {
        quitf(_wa, "Expected %d pencil indices, but got %d", k, (int)selectedIndices.size());
    }

    // Kiểm tra có chỉ số trùng lặp không
    unordered_set<int> uniqueIndices(selectedIndices.begin(), selectedIndices.end());
    if (uniqueIndices.size() != k)
    {
        quitf(_wa, "Duplicate pencil indices found");
    }

    // Tạo map để kiểm tra RGB
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> rgbExists;
    for (const Pencil &p : allPencils)
    {
        rgbExists[p.r][p.g][p.b] = true;
    }

    // Tính độ sặc sỡ của tập đã chọn
    vector<Pencil> selectedPencils;
    for (int idx : selectedIndices)
    {
        const Pencil &p = allPencils[idx - 1];

        // Kiểm tra RGB có nằm trong input không
        if (!rgbExists[p.r][p.g][p.b])
        {
            quitf(_wa, "Pencil with RGB (%d,%d,%d) at index %d not found in input", p.r, p.g, p.b, idx);
        }

        selectedPencils.push_back(p);
    }

    int actualVibrancy = getVibrancy(selectedPencils);

    // Kiểm tra độ sặc sỡ có đúng không
    if (outputVibrancy != actualVibrancy)
    {
        quitf(_wa, "Incorrect vibrancy value. Output: %d, Actual: %d", outputVibrancy, actualVibrancy);
    }

    // Đọc answer (từ file ans) để so sánh với output
    int ansVibrancy = ans.readInt();

    // Nếu output chính xác nhưng không tối ưu
    if (outputVibrancy > ansVibrancy)
    {
        quitf(_wa, "Non-optimal solution. Output vibrancy: %d, Optimal vibrancy: %d", outputVibrancy, ansVibrancy);
    }

    quitf(_ok, "Correct output with vibrancy: %d", outputVibrancy);
    return 0;
}
