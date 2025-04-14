
double min_so_far {0};
double max_so_far {0};

min_so_far = min_so_far > num ? num : min_so_far;
max_so_far = max_so_far < num ? num : max_so_far;

cout << "min_so_far" << min_so_far << '\n';
cout << "max_so_far" << max_so_far << '\n';