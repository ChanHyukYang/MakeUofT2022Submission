import numpy as np

NUM_ROW:int = 8
NUM_COL:int = 8

NUM_ROTATIONS:int = 3

LED_PRESETS:list = [
    [60, 50, 46, 33, 30, 17, 13, 3],
    [60, 52, 42, 37, 26, 21, 11, 3],
    [44, 45, 33, 36, 27, 30, 19, 18],
    [53, 52, 51, 45, 41, 37, 33, 30, 26, 22, 18, 12, 11, 10],
    [62, 61, 60, 51, 49, 46, 45, 44, 30, 29, 28, 27, 26, 25, 24, 19, 13, 11, 5, 1],
    [41, 39, 31, 29, 28, 24, 22, 21, 20],
    [54, 49, 45, 42, 36, 35, 28, 27, 21, 18, 14, 9],
    [31, 29, 28, 27, 26, 25, 24],
    [61, 60, 59, 58, 57, 54, 52, 43, 41, 29, 28, 27, 26, 25, 18, 13, 12, 11, 10, 9],
    [60, 59, 58, 54, 52, 43, 40, 39, 36, 27, 24, 23, 20, 11, 9, 5, 4, 3]
]

def main():
    
    for preset in LED_PRESETS:
        original_matrix:np.ndarray = np.zeros(shape=(NUM_ROW, NUM_COL), dtype=int)
        output_list:list = []
        for led_pos in preset:
            row_num = led_pos//8
            col_num = led_pos%8
            
            # shift so that alternates direction from row to row
            real_col_num = col_num if row_num%2 == 0 else NUM_COL-col_num-1

            original_matrix[row_num, real_col_num] = 1
        
        rotated_matrix = np.rot90(original_matrix, k=NUM_ROTATIONS)
        
        for row_num, row in enumerate(rotated_matrix):
            for col_num, ele in enumerate(row):
                if ele == 1:
                    
                    real_col_num = col_num if row_num%2 == 0 else NUM_COL-col_num-1
                    
                    output_list.append(row_num*NUM_COL+real_col_num)
                    
        #print(original_matrix)
        #print(rotated_matrix)
        print(output_list)
        
main()