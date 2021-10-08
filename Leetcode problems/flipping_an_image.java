/*
Flipping an Image

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
*/

class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        int l=image.length;
        for(int i=0;i<l;i++){
            for(int j=0;j*2<l;j++){
                if(image[i][j]==image[i][l-j-1]){
                    image[i][j]^=1;
                    image[i][l-j-1]=image[i][j];
                }
            }
        }
        return image;
    }
}