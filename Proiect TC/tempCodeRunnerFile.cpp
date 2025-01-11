int tempId;
		file >> tempId;
		if (file) {
			const_cast<int&>(a.id) = tempId;
		}