jQuery(function(){
	initTabs();
});
jQuery(document).ready(function(){
	//init forms
	jQuery('input:radio').customRadio();
	//jQuery('select').customSelect();
	//jQuery('select:not(".not-castom")').customSelect();
	//jQuery('select.custom-select').customSelect();
	//jQuery('input:checkbox').customCheckbox();

	//init gallery
	jQuery('div.content-slider').gallery({
		duration: 500,
		listOfSlides: '.content-slider-list > li'
	});
	jQuery('div.side-slider').gallery({
		duration: 500,
		listOfSlides: '.side-slider-list > li',
		switcher: '.side-slider-nav>li'
	});
	jQuery('.open-search-panel').click(function () {
		jQuery('.search-panel').slideDown();
		jQuery('.search-btn').addClass("active");
		return false;
	});
	jQuery('.close-search-panel').click(function () {
		jQuery('.search-panel').slideUp();
		jQuery('.search-btn').removeClass("active");
		return false;
	});
});
// tabs init
function initTabs() {
	jQuery('ul.tabset').contentTabs({
		animSpeed:500,
		effect: 'none'
	});
}