#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string.h>
#include <sstream>
#include <climits>
#include <deque>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		~PmergeMe();
		PmergeMe &		operator=( PmergeMe const & rhs );
		std::deque<int> deque;
		std::vector<int> vector;

		template <typename T> 
		void	recursive(T &contain, int begin, int end) {
			int mid = (begin + end) / 2;
			if (begin < end) {
				recursive(contain, begin, mid);
				recursive(contain, mid + 1, end);
				merge(contain, begin, mid, end);
			}
		}

		template <typename T> 
		void	merge(T &contain, int left, int mid, int right) {
			std::vector<int> tmp(right - left + 1);
			int i = left; int j = mid + 1; int k = 0;
			while (i <= mid && j <= right) {
				if (contain[i] < contain[j])
					tmp[k++] = contain[i++];
				else
					tmp[k++] = contain[j++];
			}
			while (i <= mid) 
				tmp[k++] = contain[i++];
			while (j <= right) 
				tmp[k++] = contain[j++];
			for (int p = 0; p < k; p++) 
				contain[left + p] = tmp[p];
		}
};

#endif