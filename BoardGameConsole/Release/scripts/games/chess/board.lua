local chessboard = {}
chessboard.height = 8
chessboard.width = 8

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
chessboard.state = state

local squares = {}
for s=1, 64, 1 do
	local newSquare	= {}
	if s % chessboard.height == 0 then

	end
	newSquare.state =
	squares[s] = newSquare
end
