#include "gui/components/components.hpp"

namespace big
{
	void components::custom_text(const std::string_view text, ImFont* font)
	{
		ImGui::PushFont(font);

		const auto pos = ImGui::GetCursorScreenPos();
		auto draw_list = ImGui::GetWindowDrawList();

		// Text settings
		ImVec2 text_pos     = pos;
		ImU32 glow_color    = IM_COL32(128, 0, 255, 180);        // Purple glow
		ImU32 text_color    = ImGui::GetColorU32(ImGuiCol_Text); // Default text color
		float glow_strength = 1.0f;                              // thickness of glow
		float spread        = 2.0f;                              // spread range of glow

		// Draw glow
		for (float x = -spread; x <= spread; x += glow_strength)
		{
			for (float y = -spread; y <= spread; y += glow_strength)
			{
				if (x == 0.0f && y == 0.0f)
				{
					continue;
				}
				draw_list->AddText(font, font->FontSize, ImVec2(text_pos.x + x, text_pos.y + y), glow_color, text.data());
			}
		}

		// Draw the main text
		draw_list->AddText(font, font->FontSize, text_pos, text_color, text.data());

		// Advance cursor
		ImVec2 text_size = font->CalcTextSizeA(font->FontSize, FLT_MAX, 0.0f, text.data());
		ImGui::Dummy(ImVec2(text_size.x, text_size.y)); // Move cursor after text

		ImGui::PopFont();
	}
}
