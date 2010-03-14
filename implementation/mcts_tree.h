#ifndef MCTS_TREE_H_
#define MCTS_TREE_H_

#include "hextypes.h"
#include "mcts_node.h"

namespace Hex {

class MCTSTree {
public:
	MCTSTree();
	void ClearTree();
	void Reset();
	Move BestMove(Player player, Board& board);
	Player RandomFinish(Board& board, uint* path, uint current_level);
	Player RandomFinishWithoutPath(Board& board);
	void SetMaxDepth(uint depth);
	void SetPlayoutsPerMove(uint playouts);
	std::string ToAsciiArt(uint children);

friend class MCTSNode;

private:
	AutoPointer<MCTSNode> root;
	Player current_player;
	uint max_depth;
	uint playouts_per_move;
	uint root_children_number;
	static const uint default_max_depth;
	static const uint default_playouts_per_move;
	static const uint ultimate_depth;
	static const uint visits_to_expand;
	static const uint amaf_paths_palyouts;
};

} // namespace Hex

#endif /* MCTS_TREE_H_ */
