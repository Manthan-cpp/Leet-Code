class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int al=abs(ax2-ax1),ab=abs(ay2-ay1),overlap=0;
        int bl=abs(bx2-bx1), bb=abs(by2-by1);
        int a1=al * ab;
        int a2=bl*bb;
        int left = max(ax1,bx1);
        int right = min(ax2,bx2);
        int width=right-left;
        left=max(ay1,by1);
        right=min(ay2,by2);
        int length = right - left;
        if(length<=0 || width<=0){
            overlap=0;
        }
        else
        overlap = length*width;
        return a1+a2-overlap;
    }
};