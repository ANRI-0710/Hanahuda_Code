#pragma once

namespace t2k {

	// �_�Ƌ�`�̏Փ˔���
	bool isIntersectPointRect(const int point_x, const int point_y, const int rect_x, const int rect_y, const int rect_size);

	// ��`�Ƌ�`
	bool isIntersectRect(const int a_rect_x, const int a_rect_y, const int a_rect_size_w, const int a_rect_size_h,
		const int b_rect_x, const int b_rect_y, const int b_rect_size_w, const int b_rect_size_h);

}
