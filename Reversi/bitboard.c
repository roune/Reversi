#include "bitboard.h"

uint8_t get_bit(uint64_t bits, int pos) {
   return (bits >> pos) & 0x01;
}

uint64_t set_bit(uint64_t bits, int pos, int value) {
   uint64_t mask = 1LL << (63 - pos);
   if (value)
       bits |= mask;
   else
       bits &= ~mask;
   return bits;
}

bitboard_t bb_new(size_t size) {
	bitboard_t board;
	
	return board;
}

bitboard_t bb_set(move_t move, state_t state) {
	int pos;
	bitboard_t board;
	board.size = state.board.size;
	pos = move.row * state.board.size + move.column;
	
	if (state.player == BLACK_STONE) {
		board.black = set_bit(state.board.black, pos, 1);
	} else {
		board.white = set_bit(state.board.white, pos, 1);
	}
	
	return board;
}

bitboard_t bb_init(size_t size) {
	bitboard_t board;
	
	board = bb_new(size);
	
	int first_row, first_col, first_empty, second_empty;
	
	first_row = size/2 - 1;
	first_col = size/2 - 1;
	first_empty = first_row * size + first_col;
	second_empty = (first_row + 1) * size + first_col;
	
	board.size = size;
	board.black = board.white = 0;
	board.white = set_bit(board.white, first_empty, 1);
	board.black = set_bit(board.black, first_empty + 1, 1);
	board.black = set_bit(board.black, second_empty, 1);
	board.white = set_bit(board.white, second_empty + 1, 1);
	
	return board;
}

void bb_print(bitboard_t board) {
	uint64_t full_board = 0;
	int i;
	printf("\t");
	for (i = 0; i < board.size; i++) {
		printf("%d ", i);
	}
	
	full_board = board.white & board.black;
	
	for (i = 0; i < board.size * board.size; i++) {
		if (i % board.size == 0) {
			printf("\n");
			switch(i / board.size) {
				case 0:
					letter = 'A';
					break;
				case 1:
					letter = 'B';
					break;
				case 2:
					letter = 'C';
					break;
				case 3:
					letter = 'D';
					break;
				case 4:
					letter = 'E';
					break;
				case 5:
					letter = 'F';
					break;
				case 6:
					letter = 'G';
					break;
				case 7:
					letter = 'H';
					break;
			}
			printf("%c\t", letter);
		}
		if (get_bit(full_board, i)) {
			if (get_bit(board.white)) {
				printf("O ");
			} else {
				printf("X ");
			}
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

score_t bb_score(bitboard_t board) {
	score_t score;
	size_t black, white;
	int i;
	black = white = 0;
	
	for (i = 0; i < 64; i++) {
		if (get_bit(board.black, i))
			black++;
		else if (get_bit(board.white, i))
			white++;
	}
	score.black = black;
	score.white = white;
	return score;
}

int one_dimension(int x, int y, size_t size) {
	return y*size + x;
}

bitboard_t bb_up(move_t move, state_t state, bool change) {
	int x = move.row, y = move.column, i;
	bool changed = false;
	char player = state.player;
	size_t size = state.board.size;
	bitboard_t * board = state.board, res;
	res.size = 0;
	uint64_t black = board.black, white = board.white;
	
	if (y < 8) {
		return res;
	}
	
	if (player == BLACK_STONE) {
		if (get_bit(white, one_dimension(x, y-8, size)) != 1)
			return res;
	} else {
		if (get_bit(black, one_dimension(x, y-8, size)) != 1)
			return res;
	}
	
	for(i = y-8; i >= 0; i -= 8) {
		if (player == BLACK_STONE) {
			if (get_bit(black, one_dimension(x, y, size)) == 1) {
				return board;
			}
			if (get_bit(white, one_dimension(x, y, size)) == 1) {
				if (change) {
					set_bit(white, one_dimension(x, y, size), 0);
					set_bit(black, one_dimension(x, y, size), 1);
				}
			} else {
				return res;
			}
		} else {
			if (get_bit(white, one_dimension(x, y, size)) == 1) {
				return board;
			}
			if (get_bit(black, one_dimension(x, y, size)) == 1) {
				if (change) {
					set_bit(black, one_dimension(x, y, size), 0);
					set_bit(white, one_dimension(x, y, size), 1);
				}
			} else {
				return res;
			}
		}
	}
	
}
bool bb_down(move_t move, state_t state) {
	
}
bool bb_right(move_t move, state_t state) {
	
}
bool bb_left(move_t move, state_t state) {
	
}
bool bb_up_right(move_t move, state_t state) {
	
}
bool bb_up_left(move_t move, state_t state) {
	
}
bool bb_down_right(move_t move, state_t state) {
	
}
bool bb_down_left(move_t move, state_t state) {
	
}

bitboard_t bb_move(move_t move, state_t state) {
	bool moved = false;
	
	//FALTA COMPROBAR QUE MOVE NO SEA MAYOR AL TABLERO
	//FALTA COMPROBAR QUE NO ESTE OCUPADA
	
	if (bb_up(move, state, false)) {
		bb_up(move, state, true);
	}
	if (bb_down(move, state, false)) {
		
	}
	if (bb_right(move, state, false)) {
		
	}
	if (bb_left(move, state, false)) {
		
	}
	if (bb_up_right(move, state, false)) {
		
	}
	if (bb_up_left(move, state, false)) {
		
	}
	if (bb_down_right(move, state, false)) {
		
	}
	if (bb_down_left(move, state, false)) {
		
	}
	
	
}

bitboard_t bb_moves(state_t state) {
	
}

int score_heuristic (state_t state) {
	score_t score;
	
	score = bb_score(state.board);
	
	if (state.player == BLACK_STONE) {
		return score.black;
	}
	return score.white;
}

int max(a, b) {
	int c = a-b;
	if (c > 0) {
		return a;
	} else if (c == 0) {
		return a;
	} else {
		return b;
	}
}

int min(a, b) {
	int c = b-a;
	if (c > 0) {
		return a;
	} else if (c == 0) {
		return a;
	} else {
		return b;
	}
}

move_t minmax_aux(bitboard_t board, char player, int depth, int (*heuristic) state_t state, int maximizing) {
	int best_value, i, v;
	bitboard_t aux_board;
	state_t state;
	if (depth = 0 or bb_moves(state) == 0) {
		state.board = board;
		state.player = player;
		return (*heuristic)(state);
	}

	if (maximizing) {
		best_value = INT_MIN;
		aux_board = bb_moves(state);
		for (i = 0; i < state.board.size; i++) {
			if (state.player == BLACK_STONE) {
				if (get_bit(aux_board.black, i)) {
					v = minimax_aux(aux_board, WHITE_STONE, depth - 1, heuristic, 0);
					best_value = max(v, best_value);
				}
			} else {
				if (get_bit(aux_board.white, i)) {
					v = minimax_aux(aux_board, BLACK_STONE, depth - 1, heuristic, 0);
					best_value = max(v, best_value);
				}
			}
		}
		return best_value;
	} else {
		best_value = INT_MAX;
		aux_board = bb_moves(state);
		for (i = 0; i < state.board.size; i++) {
			if (state.player == BLACK_STONE) {
				if (get_bit(aux_board.black, i)) {
					v = minimax_aux(aux_board, WHITE_STONE, depth - 1, heuristic, 1);
					best_value = min(v, best_value);
				}
			} else {
				if (get_bit(aux_board.white, i)) {
					v = minimax_aux(aux_board, BLACK_STONE, depth - 1, heuristic, 1);
					best_value = min(v, best_value);
				}
			}
		}
		return best_value;
	}
}

move_t minmax(state_t state, int depth, int (*heuristic) state_t state) {
	return minmax_aux(state.board, state.player, depth, heuristic, 1);
}

move_t negamax(state_t state, int depth, int (*heuristic) state_t state) {
	
}

move_t minmax_alphabeta(state_t state, int depth, int (*heuristic) (state_t state)) {
	
}

move_t negamax_alphabeta(state_t state, int depth, int (*heuristic) (state_t state)) {
	
}

static move_t ai_player(state_t state) {
	
}