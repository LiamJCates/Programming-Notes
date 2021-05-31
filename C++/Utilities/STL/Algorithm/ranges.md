Most of the algorithms can be used with both ranges and iterators, some exist only in iterator form.

The range-flavored algorithms live in the std::ranges namespace, which helps keep the algorithms organized.

For example, the following are the two forms of the copy algorithm, both copying the contents of data to the standard output:

std::copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout));

std::ranges::copy(data, std::ostream_iterator<int>(std::cout));

Helper iterators, such std::ostream_iterator, are declared in the <iterator> module. Range helpers, such as std::ranges::istream_view, are declared in the <ranges> module.
