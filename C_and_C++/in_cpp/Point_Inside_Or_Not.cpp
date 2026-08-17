#include <iostream>
#include <vector>

bool on_the_line(int x, int y, int x1, int y1, int x2, int y2) {
    return ((x >= std::min(x1, x2)) && (x <= std::max(x1, x2))) && ((y >= std::min(y1, y2)) && (y <= std::max(y1, y2)));
}
int main() {
    std::vector<std::pair<int, int>> vertices;
    int n;
    std::cin >> n;
    int x,y;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> x >> y;
        vertices.emplace_back(x, y);
    }
    std::cin >> x >> y;
    int s1 = ((vertices[0].first - x)*(vertices[1].second - y)) - ((vertices[1].first - x)*(vertices[0].second - y));
    int s2 = ((vertices[1].first - x)*(vertices[2].second - y)) - ((vertices[2].first - x)*(vertices[1].second - y));
    int s3 = ((vertices[2].first - x)*(vertices[0].second - y)) - ((vertices[0].first - x)*(vertices[2].second - y));

    if ((s1 == 0) && (on_the_line(x , y, vertices[0].first, vertices[0].second, vertices[1].first, vertices[1].second))) {
        std::cout << "On the line" << "\n";
    }
    else if ((s2 == 0) && (on_the_line(x , y, vertices[1].first, vertices[1].second, vertices[2].first, vertices[2].second))) {
        std::cout << "On the line" << "\n";
    }
    else if ((s3 == 0) && (on_the_line(x , y, vertices[0].first, vertices[0].second, vertices[2].first, vertices[2].second))) {
        std::cout << "On the line" << "\n";
    }
    else if (((s1 > 0) && (s2 > 0) && (s3 > 0))||((s1 < 0) && (s2 < 0) && (s3 < 0))) {
        std::cout << "Inside" << "\n";
    }
    else {
        std::cout << "Outsize" << "\n";
    }
}