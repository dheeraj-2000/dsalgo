import pygame
import math
from queue import PriorityQueue

WIDTH = 800
WIN = pygame.display.set_mode((WIDTH, WIDTH))
pygame.display.set_caption("A* Path Finding Algorithm")

RED = (255,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)
YELLOW = (255,0,0)
WHITE = (255,255,255)
BLACK = (0,0,0)
PURPLE = (128,0,128)
ORANGE = (255,165,0)
GREY = (128,128,128)
TURQUOISE = (24,224,208)

class Spot:
    def __init__(self,row,col,width,total_rows):
        # super().__init__()
        self.row = row
        self.col = col
        self.x = row * width
        self.y = col * width
        self.color = WHITE
        self.neighbors = []
        self.width = width
        self.total_rows = total_rows
    
    def get_pos(self):
        return self.row,self.col
    
    def is_closed(self):
        return self.color == RED

    def is_open(self):
        return self.color ==GREEN     
    
    def is_barrier(self):
        return self.color ==BLACK
    
    def is_start(self):
        return self.color == ORANGE

    def is_emd(self):
        return self.color == TURQUOISE

    def reset(self):
        self.color = WHITE

    def make_closed(self):
        self.color = RED
    
    def make_open(self):
        self.color = GREEN
    
    def make_barrier(self):
        self.color = BLACK
    
    def make_end(self):
        self.color = TURQUOISE
    
    def make_path(self):
        self.color = PURPLE
    
    def make_start(self):
        self.color = ORANGE

    def  draw(self,win):
        pygame.draw.rect(win,self.color,(self.x,self.y,self.width,self.width))
#  checkimg that the finding algo doesnot cross any black sqaures
#    it is to confirm that the if the frame end so the traversing finding nodes does not chechk frame and crash it will chechk that the 
# down the row it is not frame then traverse.
    def update_neighbors(self,grid):
        self.neighbors = []
       #down
        if self.row < self.total_rows - 1 and not grid[self.row+1][self.col].is_barrier():
            self.neighbors.append(grid[self.row +1][self.col])
        #up
        if self.row > 0 and not grid[self.row-1][self.col].is_barrier():
            self.neighbors.append(grid[self.row -1][self.col])
        #Right
        if self.col < self.total_rows - 1 and not grid[self.row][self.col + 1].is_barrier():
            self.neighbors.append(grid[self.row][self.col+1])
        #Left
        if self.col >0 and not grid[self.row][self.col-1].is_barrier():
            self.neighbors.append(grid[self.row][self.col-1])


    def __lt__(self,other):
        return False

def h(p1,p2):
    x1, y1 = p1
    x2, y2 = p2

    return abs(x1 - x2) +abs(y1 - y2)
def reconstruct_path(came_from,current,draw):
    while current in came_from:
        current = came_from[current]
        current.make_path()
        draw()

def algorithm(draw,grid,start,end) :
    count = 0
    open_set = PriorityQueue()
    open_set.put((0,count,start))
    came_from = {}
    g_score = {spot: float("inf") for row in grid for spot in row}
    g_score[start] = 0

    f_score = {spot: float("inf") for row in grid for spot in row}
   
#whenwe reach the end node it doenot imagoine the best path 
    f_score[start] = h(start.get_pos(),end.get_pos())
    
    open_set_hash = {start}

    while not open_set.empty():
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
        #getting the minimum value in the open set taht is the shoetrest distnace between tehsatrt node and the end node
        current = open_set.get()[2]
        open_set_hash.remove(current)

        if current == end:
            # make path
            reconstruct_path(came_from,end,draw)
            end.make_end()
            return True
# distance to start node and end node and we add the 1 to knwo the distance to the ned node
        for neighbor  in current.neighbors:
            temp_g_score = g_score[current] + 1

            if temp_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = temp_g_score 
                f_score[neighbor] = temp_g_score +h(neighbor.get_pos(),end.get_pos())
                
                if neighbor not in open_set_hash:
                    count+=1
                    open_set.put((f_score[neighbor],count,neighbor))
                    open_set_hash.add(neighbor)
                    neighbor.make_open()
        draw()

        if current!=start:
            current.make_closed()
    return False

# It will draw the rectangles throughtout the frame
def make_grid(rows,width):
    grid = []
    gap =width// rows
    # It will decide teh numver of cubes in the frame
    for i in range(rows):
        grid.append([])
        for j in range(rows):
            spot = Spot(i, j,gap,rows)
            grid[i].append(spot)
    return grid

# now we have to make the grid lines so that all if the rectangel lines are vsibile
def draw_grid(win,rows,width):
    gap = width//rows
    for i in range(rows):
        pygame.draw.line(win,GREY,(0,i*gap),(width,i *gap))
        for j in range(rows):
            pygame.draw.line(win,GREY,(j*gap,0),(j*gap,width))

def draw(win,grid,rows,width):
    win.fill(WHITE)

    for row in grid:
        for spot in row:
            spot.draw(win)
    
    draw_grid(win,rows,width)
    pygame.display.update()

def get_clicked_pos(pos,rows,width):
    gap = width//rows
    y, x = pos

    row = y // gap
    col = x // gap
    return row,col

def main(win,width):
    ROWS = 50
    grid = make_grid(ROWS,width)

    start = None
    end = None
    run = True
    started = False
    # Chechking that all the evnts happend like the suer likde somethjing or changeed something this block will chekc this all

    while run:
        draw(win,grid,ROWS,width)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            
            # if started:
            #     continue
            # Mouse location pointing
            if pygame.mouse.get_pressed()[0]:   #LEFT
                pos = pygame.mouse.get_pos()
                row, col = get_clicked_pos(pos,ROWS,width)
                spot  = grid[row][col]
                
                # if the start or end position is not clicked then we make the the start and end the same
                if not start and spot!=end:
                    start = spot
                    start.make_start()
                
                elif not end and spot!=start:
                    end = spot
                    end.make_end()
                
                elif spot !=end and spot!=start:
                    spot.make_barrier()

            elif pygame.mouse.get_pressed()[2]: #RIGHT
                pos = pygame.mouse.get_pos()
                row,col = get_clicked_pos(pos,ROWS,width)
                spot = grid[row][col]
                spot.reset()
                if spot == start:
                    start=None
                elif spot == end:
                    end= None
            if event.type ==pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and start and end:
                    for row in grid:
                        for spot in row:
                            spot.update_neighbors(grid)
                    algorithm(lambda: draw(win,grid,ROWS,width),grid,start,end)#capital L and small l in lambada

                if event.key ==pygame.K_c:
                    start = None
                    end=None
                    grid = make_grid(ROWS,width)
                    
            
    pygame.quit()
main(WIN,WIDTH)


         
    

















