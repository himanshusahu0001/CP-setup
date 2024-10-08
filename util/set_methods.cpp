template <typename T>
std::multiset<T> intersection(const std::multiset<T>& set1, const std::multiset<T>& set2) {
    std::multiset<T> result;
    std::multiset<T> set1_copy(set1.begin(), set1.end());
    std::multiset<T> set2_copy(set2.begin(), set2.end());

    std::set_intersection(set1_copy.begin(), set1_copy.end(), set2_copy.begin(), set2_copy.end(),
                         std::inserter(result, result.begin()));

    return result;
}