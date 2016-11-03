# ConsidRegScanner
Application written for a programming competition held by Consid. The goal was to search through 6 000 000 registrations
as fast as possible.

Initially implementation was done using a HashMap in order to achieve O(n) time complexity. However, this caused a majority of
the time being spent hashing values. Instead the implementation moved towards a simple sorting algorithm and then comparing
values that reside close together. Currently the application uses C++' stnadard library sort. However, one could potentially
improve the application further by using a modified version of MSD Radix Sort.
