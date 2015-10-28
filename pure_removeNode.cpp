void removeNode(int val, LinkedList **list) {
	LinkedList* node = *list;
	LinkedList* nextNode;
	LinkedList* tmpNode;

	if (!node) {
		return;
	}
	nextNode = node->next;

	while (nextNode) {
		if (nextNode->val == val) {
			tmpNode = nextNode;
			nextNode = nextNode->next;
			node->next = nextNode;
			delete(tmpNode);
		}
		else {
			node = node->next;
			nextNode = nextNode->next;
		}
	}
	node = *list;
	if (node->val == val) {
		*list = node->next;
		delete(node);
	}
}