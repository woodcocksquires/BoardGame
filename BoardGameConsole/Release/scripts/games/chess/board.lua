local board = {}
board.height = 8
board.width = 8

local state = {}

local whiteState = {}
whiteState.identifier = "W"
whiteState.name = "White"
whiteState.value = 1

local blackState = {}
blackState.identifier = "B"
blackState.name = "Black"
blackState.value = 1

state[1] = whiteState
state[2] = blackState
board.state = state

local locations = {}
for s=1, board.height*board.width, 1 do
	local newLocation	= {}
	local row = math.floor((s-1) / board.width)
	local col = (s-1-(row*board.width)) % board.width
	if (((row % 2) + (col % 2)) % 2 == 0) then
		newLocation.state = whiteState
	else
		newLocation.state = blackState
	end
	local halfHeight = (board.height-1)/2
	local halfWidth = (board.width-1)/2
	local maxScore = 5
	local heightScore = math.ceil(maxScore * (1 - (math.abs(row-halfHeight))/halfHeight))
	local widthScore =  math.ceil(maxScore * (1 - (math.abs(col-halfWidth))/halfWidth))
	newLocation.value = heightScore + widthScore
	locations[s] = newLocation

	--print("s-1", s-1, "row", row, "col", col, "value", newSquare.value, "state", newSquare.state.name)
end
board.locations = locations

wsq.boardgame.games.chess.board = board
