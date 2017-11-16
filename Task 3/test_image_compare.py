#!/usr/bin/env python

import pytest
from scipy import misc	#misc.imread
import numpy as np		#numpy
import math				#math.sqrt

def rmse(img1, img2):
	#convert each to floating point values
	img1_fl = img1.astype('float64')
	img2_fl = img2.astype('float64')
	#get the piecewise difference
	img_dif = img1_fl - img2_fl
	#square the piecewise difference
	img_sq_dif = np.square(img_dif)
	#sum all the elements
	sum = np.sum(img_sq_dif)
	#take the mean of the elements
	mean = sum / float(img1.size)
	#take the square root of that mean
	#return it
	return math.sqrt(mean)
	#OR return math.sqrt(np.sum(np.square(img1.astype('float64') - img2.astype('float64')) / float(img1.size))
	

def test_rmse():
	#load first image
	img0 = misc.imread("w0.png")
	#load second image
	img1 = misc.imread("w1.png")
	#load some ones and zeros
	ones = np.ones([3,3])
	zeros = np.zeros([3,3])
	
	#test 1: All ones. The rmse should be 0 because the images are identical
	assert rmse(ones, ones) == 0.0
	#test 2: All zeros. The rmse should be 0 because the images are identical
	assert rmse(zeros, zeros) == 0.0
	#test 3: One with Zeros and one with Ones. The rmse should be 1
	assert rmse(ones, zeros) == 1.0
	#test 4: Same as the last test but in reverse order.
	#The order shouldn't matter, so the rmse should still be 1
	assert rmse(zeros, ones) == 1.0
	#test 5: the loaded image data. The rmse should be something non-zero
	assert rmse(img0, img1) != 0.0



