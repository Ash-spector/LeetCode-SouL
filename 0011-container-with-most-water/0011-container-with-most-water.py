class Solution:
    def maxArea(self, height: list[int]) -> int:
        max_water = 0
        left = 0
        right = len(height) - 1
        
        while left < right:
            # Calculate width and find the limiting height
            width = right - left
            current_height = min(height[left], height[right])
            
            # Calculate current water capacity
            current_water = width * current_height
            
            # Track peak volume
            if current_water > max_water:
                max_water = current_water
            
            # Evict the shorter line to look for a taller bottleneck
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return max_water
